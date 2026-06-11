#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>w(n);
    for(int i=0;i<n;i++)cin >> w[i];
    int weigh=100000000;
    for(int i=0;i<n-1;i++){
        int now_up=0;
        int now_down=0;
        for(int j=0;j<=i;j++){
            now_down+=w[j];
        }
        for(int j=i+1;j<=n-1;j++){
            now_up+=w[j];
        }
        int now=abs(now_up-now_down);
        if(now<weigh)weigh=now;
    }
    cout << weigh;
}