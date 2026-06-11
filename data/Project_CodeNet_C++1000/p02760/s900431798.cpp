#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    map<int,pair<int,int>> mp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int x;
            cin>>x;
            mp.insert({x,{i,j}});
        }
    }
    int arr[3][3]={};
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(mp.count(x)){
            pair<int,int> p=mp[x];
            arr[p.first][p.second]=1;
        }
    }
    for(int i=0;i<3;i++){
        int temp=0;
        for(int j=0;j<3;j++){
            if(arr[i][j])temp++;
        }
        if(temp==3){
            cout<<"Yes";
            return 0;
        }
    }
    for(int j=0;j<3;j++){
        int temp=0;
        for(int i=0;i<3;i++){
            if(arr[i][j])temp++;
        }
        if(temp==3){
            cout<<"Yes";
            return 0;
        }
    }
    if(arr[0][0]&&arr[1][1]&&arr[2][2]){
        cout<<"Yes";
        return 0;
    }
    if(arr[2][0]&&arr[1][1]&&arr[0][2]){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}

