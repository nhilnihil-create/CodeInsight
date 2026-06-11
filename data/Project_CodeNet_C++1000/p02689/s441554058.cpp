#include <bits/stdc++.h>
using namespace std;

int main(){
    //cout << endl;
    int n,m;
    cin >> n >> m;
    vector<pair<int,vector<int>>> tenbou(n);
    for(int i=0;i<n;i++) cin >> tenbou.at(i).first;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        tenbou.at(x-1).second.push_back(y);
        tenbou.at(y-1).second.push_back(x);
    }

    /*for(int i=0;i<n;i++){
        cout << tenbou.at(i).first << " ";
        for(int j=0;j<tenbou.at(i).second.size();j++){
            //cout << tenbou.at(i).second.at(j) << " ";
        }
        //cout << endl;
    }*/


    int cnt = 0;
    for(int i=0;i<n;i++){
        vector<int> arr = tenbou.at(i).second;
        int height = tenbou.at(i).first;
        bool flag = true;
        for(int j=0;j<arr.size();j++){
            int idx = arr.at(j)-1;
            if(height <= tenbou.at(idx).first){
                flag = false;
                break;
            }
        }
        //cout << i << " " << flag << endl;
        if(flag){
            cnt++;
        }
        
    }
    cout << cnt << endl;
}