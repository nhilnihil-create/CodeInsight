#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> array(n);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        vector<pair<int,int>> arr(a);
        for(int j=0;j<a;j++){
           cin >> arr.at(j).first >> arr.at(j).second;
        }
        array.at(i) = arr;
    }
    int max = -1;
    for(int tmp=0; tmp < ( 1 << n); tmp++){
        bool flag = true;
        int cnt = 0;
        bitset<15> s(tmp);
        for(int i=0;i<n;i++){
            if(s.test(i)){
                cnt++;
                //cout << cnt << endl;
                vector<pair<int,int>> syougen_array = array.at(i);
                int size = syougen_array.size();
                for(int j=0;j<size;j++){
                    pair<int,int> syougen = syougen_array.at(j);
                    int person = syougen.first;
                    int honest = syougen.second;
                    if(honest == 1){
                        if(!s.test(person-1)){
                            flag = false;
                            break;
                        }
                    }else {
                        if(s.test(person-1)){
                            flag = false;
                            break;
                        }
                    }
                }
                
            }
            if(!flag) break;
            
        }
        if(flag){
            if(max < cnt) max = cnt;
        }else{
            continue;
        }
    }

    cout << max << endl;
}