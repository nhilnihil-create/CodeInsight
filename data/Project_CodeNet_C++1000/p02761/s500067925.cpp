#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    vector<int> count(n);

    bool flag=true;
    for(int i=0;i<m;i++) {
        int s,c;
        cin>>s>>c;

        if(count[s-1]!=0&&arr[s-1]!=c) flag=false;
        else {
            arr[s-1]=c;
            count[s-1]++;
        }
    }
    if(count[0]!=0&&arr[0]==0&&n!=1) flag=false;

    if(flag) {
        if(arr[0]==0&&n!=1) {
            arr[0]=1;
        }
        for(int i=0;i<n;i++) {
            cout<<arr[i];
        }
        cout<<endl;
    }
    else cout<<-1<<endl;

}


