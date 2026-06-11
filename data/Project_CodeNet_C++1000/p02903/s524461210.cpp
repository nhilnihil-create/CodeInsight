#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
long long h,w,a,b;
int main(){
    ios::sync_with_stdio(0);
    cin>>h>>w>>a>>b;
    if (a==0&&b==0){
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cout<<0;
            }
            cout<<endl;
        }
        return 0;
    }
    if (a==0){
        for(int i=1; i<=b; i++){
            for (int j=1; j<=w; j++) cout<<0;
            cout<<endl;
        }
        for(int i=b+1; i<=h; i++){
            for(int j=1; j<=w; j++) cout<<1;
            cout<<endl;
        }
        return 0;
    }
    if (b==0){
        for(int i=1; i<=h; i++){
            for(int j=1; j<=a; j++) cout<<0;
            for(int j=a+1; j<=w; j++) cout<<1;
            cout<<endl;
        }
        return 0;
    }
    for(int i=1; i<=b; i++){
        for(int j=1; j<=a; j++) cout<<1;
        for(int j=a+1; j<=w; j++) cout<<0;
        cout<<endl;
    }
    for(int i=b+1; i<=h; i++){
        for(int j=1; j<=a; j++) cout<<0;
        for(int j=a+1; j<=w; j++) cout<<1;
        cout<<endl;
    }  
    return 0;
}