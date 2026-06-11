//Moh_K_Imar .......
//28/08/2020  ... 11,20.
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    string a;
    cin>>a;
    if(a[0]==a[1]&&a[0]!=a[2]&&a[2]==a[3]&&a[0]!=a[3])cout<<"Yes"<<endl;
    else if(a[0]==a[3]&&a[1]==a[2]&&a[0]!=a[1]&&a[0]!=a[2])cout<<"Yes"<<endl;
    else if(a[0]==a[2]&&a[1]==a[3]&&a[0]!=a[1]&&a[0]!=a[3])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

