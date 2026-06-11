/*
Sharif Hasan - CSE, PUST
Apr 24, 2020 02: 14 PM
*/
#include<bits/stdc++.h>
#define br cout<<"\n"
#define what(x) cout<<"in here var= "<<x<<"\n";

/*STL definations*/
#define pb push_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FROM(a,i,n) for(int i=a;i<n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
bool pr(long long n){
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            return true;
        }
    }
    return false;
}
/*Main function*/
int main()
{
    long long n;bool k=0;
    cin>>n;
    k=pr(n);
    
    int di=0;
    if(k){
        
        map <long long,int> p;
        for(long long i=2;i<=sqrt(n+9);i++){
            while(n%i==0){
                n/=i;
                p[i]++;
            }
        }
        if(n>1) p[n]++;
        
        for(auto a:p){
            long long pn=a.first;
            long long np=a.second;
            //cout<<pn<<" "<<np;br;
            for(int i=1;i<=np;++i){
                di++;
                np-=i;
            }
        }
        cout<<di;br;
        
    }else if(n==1){
        cout<<0;br;
    }else{
        cout<<1;br;
    }
    
    
    return 0;
}
