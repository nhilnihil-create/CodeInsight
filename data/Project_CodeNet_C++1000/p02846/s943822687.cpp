#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t[2],a[2],b[2];
    for(int i=0;i<2;i++)cin >> t[i];
    for(int i=0;i<2;i++)cin >> a[i];
    for(int i=0;i<2;i++)cin >> b[i];
    long long int move=t[0]*(a[0]-b[0])+t[1]*(a[1]-b[1]);
    long long int MAX=max(max(0LL,t[0]*(a[0]-b[0])),move);
    long long int MIN=min(min(0LL,t[0]*(a[0]-b[0])),move);
    if(move==0)cout << "infinity";
    else{
        if(MIN==0 || MAX==0)cout << 0;
        else if(move>0 && (abs(MIN)%move)!=0)cout << 2*(abs(MIN)/move+1) - 1;
        else if(move>0 && (abs(MIN)%move)==0)cout << 2*(abs(MIN)/move+1) - 2;
        else if(move<0 && (MAX%abs(move))!=0)cout << 2*(MAX/abs(move)+1) - 1;
        else if(move<0 && (MAX%abs(move))==0)cout << 2*(MAX/abs(move)+1) - 2;
    }
}