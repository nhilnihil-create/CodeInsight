#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int total = 0;
    map <int,int> mp;
    while(k--){
        int d;
        cin>>d;
        vector <int> arr;

        for(int i=0;i<d;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        for(int i=0;i<n;i++){
            mp.insert(make_pair(i+1,0));
        }
        for(int i=0;i<d;i++){
            if(mp.find(arr[i]) != mp.end()){
                mp[arr[i]]++;
            }
        }
    }
    for(auto it: mp){
            //cout<<it.first<<" "<<it.second<<"\n";
            if(it.second == 0){
                total++;
            }
        }
        cout<<total;
        return 0;
}