
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_set>

#define rep(i,n) for(int i=0;i< (n);++i)
typedef long long ll;

using namespace std;


/*
int main(){
    int N;
    cin>>N;
    double A[N];
    for(int i=0;i<N;++i){
        cin>>A[i];
        cout<<fixed<<setprecision(9)<<A[i]<<endl;
    }
    
    cout<<"------------"<<endl;
    ll count=0;
    
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            cout<<fixed<<setprecision(9)<<A[i]*A[j]<<endl;
            double tmp=A[i]*A[j];
            if(tmp==floor(tmp)){
                ++count;
            }
        }
    }
    
    cout<<count<<endl;
    
    
}

*/

ll gcd(ll a,ll b){
    while(true){
        b=b%a;
        //cout<<"b:"<<b<<endl;
        if(b==0){
            return a;
        }
        a=a%b;
         //cout<<"a:"<<a<<endl;
        if(a==0){
            return b;
        }
        
        

    }
 
}

ll lgd(ll a,ll b){
    return a*b/gcd(a,b);
}




int main(){
    ll A,B;
    cin>>A>>B;
    cout<<lgd(A,B)<<endl;
    
   
}

