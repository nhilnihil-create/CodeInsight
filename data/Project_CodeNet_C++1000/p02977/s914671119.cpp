
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1000000000000000001
#define MOD 1000000007
using namespace std;

int pow2check(int x){
    int temp=1;
    while(temp<x){
        temp*=2;
    }
    if(temp==x){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int N;
    cin >> N;


    if(pow2check(N)){
        cout<<"No"<<endl;
        return 0;
    }
    
    int temp=1;
    while(temp*2<N){
        temp*=2;
    }
    
    if(N%2==1){
        cout<<"Yes"<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<3<<endl;
        cout<<3<<" "<<N+1<<endl;
        cout<<N+1<<" "<<N+2<<endl;
        cout<<N+2<<" "<<N+3<<endl;

        for(int i=4; i<=N; i+=2){
            cout<<i<<" "<<i+1<<endl;
            cout<<i+1<<" "<<1<<endl;
            cout<<1<<" "<<N+i<<endl;
            cout<<N+i<<" "<<N+i+1<<endl;
        }
       
    }else{
        //2^n, 2^n+1, 2^n+2を構成したらいける
        cout<<"Yes"<<endl;
        cout<<temp<<" "<<temp+1<<endl;
        cout<<temp+1<<" "<<1<<endl;
        cout<<1<<" "<<N+temp<<endl;
        cout<<N+temp<<" "<<N+temp+1<<endl;
        cout<<N+temp+1<<" "<<N+1<<endl;
        
        cout<<N+temp<<" "<<N+2<<endl;
        cout<<N+2<<" "<<temp+2<<endl;
        cout<<N+temp<<" "<<N+temp+2<<endl;
        cout<<N+temp+2<<" "<<2<<endl;
        
        cout<<N+temp+2<<" "<<N+3<<endl;
        cout<<1<<" "<<3<<endl;

        

        for(int i=4; i<=temp-1; i+=2){
            cout<<i<<" "<<i+1<<endl;
            cout<<i+1<<" "<<1<<endl;
            cout<<1<<" "<<N+i<<endl;
            cout<<N+i<<" "<<N+i+1<<endl;
        }
        
        for(int i=temp+3; i<=N; i+=2){
            //cout << "i^i+1 = " << (i^(i+1))<<endl;
            cout<<i+1<<" "<<i<<endl;
            cout<<i<<" "<<(i^(i+1))<<endl;
            cout<<(i^(i+1))<<" "<<N+i+1<<endl;
            cout<<N+i+1<<" "<<N+i<<endl;
        }
 
    }
    return 0;
}
