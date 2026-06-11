
#include<bits/stdc++.h>
using namespace std;
#define f(n) for(int i=0; i<n; i++)
#define endl '\n'
#define ll long long

int main() {


    int n;
    while(cin>>n){

        int c= n/500 * 1000 ;
        n%=500; //cout<<n<<endl;
        c+=( n/5) * 5;
        cout<<c ;
    }

    return 0;
}


