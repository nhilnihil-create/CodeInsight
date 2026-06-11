#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];}
    bool b=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            if(a[i]%3!=0){
                    if(a[i]%5!=0){b=1;}
            }
        }
    }
    if(b==0){cout<<"APPROVED";}
    else {cout<<"DENIED";}
        return 0;
}
