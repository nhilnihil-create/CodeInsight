#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    unordered_set<int> setPositions;
    int flag = 1;
    for(int i = 0; i < m; i++){
        int s, c;
        cin>>s>>c;
        s -= 1;
        if(setPositions.find(s) != setPositions.end()){
            if(v[s] != c){
                cout<<"-1";
                flag = 0;
            }
        }else{
            setPositions.insert(s);
            v[s] = c;
        }
    }
    int ans = 0;
    if(setPositions.find(0) == setPositions.end()){
        if(n!=1)
        v[0] = 1;
        else
        {
            v[0] = 0;
        }
        
        setPositions.insert(0);
    }else
    {
        if(v[0] == 0 && n!=1){
            cout<<"-1";
            flag = 0;
        }
    }
    int p = 1;
    for(int i = n-1; i >= 0; i--){
        if(setPositions.find(i) != setPositions.end()){
            ans += v[i]*p;
        }
        p*=10;
    }
    if(flag)
    cout<<ans;
    return 0;
}