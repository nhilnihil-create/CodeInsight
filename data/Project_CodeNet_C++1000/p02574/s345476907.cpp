#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L
#define MOD 1e9+7

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 
#define MAX 1000001
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int seive[MAX];
void seive_h(){
    for(int i= 2; i < MAX; i++) seive[i] = i;
    for(int i = 4; i < MAX; i+=2) seive[i] = 2;
    for(int i = 3; i*i < MAX; i++){
        if(seive[i]==i){
            for(int j = i*i ; j < MAX; j += i){
                if(seive[j]==j) seive[j] = i;
            }
        }
    }
}

int main(){
    go(); 

    // code here
    seive_h();
    int n;cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    map<int,int> mp;
    int flag = 0;
    for(int x:arr){
        set<int> st;
        int num = x;
        while(num!=1){
            st.insert(seive[num]);
            num = num / seive[num];
        }
        for(int ni:st) mp[ni]++;
    }
    
    for(auto node:mp){
        if(node.second>1){
            flag = 1;
            break;
        }
    }
    if(flag==0) cout<<"pairwise coprime";
    else{
        int g = 0;
        for(int x:arr) g = gcd(x,g);
        if(g==1) cout<<"setwise coprime";
        else cout<<"not coprime";
    }
} 







