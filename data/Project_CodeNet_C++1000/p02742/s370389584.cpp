#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //c%2==0 poleta=r*c/2;
    //c%2!=0 r%2==0 r*c/2;
    //c%2!=0 r%2!=0 r-1*c/2 + 2*r-1;
    unsigned long long int r,c;
    cin>>r>>c;
    if(r==1 || c==1)
        cout<<"1";
    else if(c%2==0)
        cout<<(r*c)/2;
    else if(r%2==0 && c%2!=0)
        cout<<(r*c)/2;
    else
        cout<<((r-1)*c)/2 + (c/2)+1;
}
