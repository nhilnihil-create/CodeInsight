#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long gcd(long long x, long long y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]/=2;
    }

    while(a[0]%2==0){
           for(int i=0;i<n;++i){
            if(a[i]%2!=0){
                cout<<0<<endl;
                return 0;
            }
            a[i]/=2;
        }
        m/=2;
    }

    for(int i=0;i<n;++i){
        if(a[i]%2==0){
            cout<<0<<endl;
            return 0;
        }
    }

    long long lcm=1;
    for(int i=0;i<n;++i){
        long long g=gcd(lcm,a[i]);
        lcm=lcm/g*a[i];
        if(lcm>m){
            cout<<0<<endl;
            return 0;
        }
    }

    cout<<(m/lcm+1)/2<<endl;
}