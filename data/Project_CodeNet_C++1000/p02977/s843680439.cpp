#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int n;
    cin>>n;
  if(n==3){
    cout<<"Yes"<<endl;
    for(int i=0; i<5; i++) cout<<i+1<<" "<<i+2<<endl;
    return 0;
  }
    int p=1;
    while(p<=n){
        if(p==n){
            cout<<"No"<<endl;
            return 0;
        }
        p<<=1;
    }
    p>>=1;
    cout<<"Yes"<<endl;
    if(n%2==1){
        for(int i=1; i<p-1; i++){
            cout<<i<<" "<<i+1<<endl;
        }
        cout<<p-1<<" "<<n+1<<endl;
        for(int i=1; i<p-1; i++){
            cout<<i+n<<" "<<i+1+n<<endl;
        }
        for(int i=p; i<n; i+=2){
            cout<<i<<" "<<i+1<<endl;
            cout<<i+1<<" "<<1<<endl;
            cout<<1<<" "<<n+i<<endl;
            cout<<n+i<<" "<<n+i+1<<endl;
        }
        return 0;
    }
    vector<int> v;
    set<int> st;
    for(int i=0; i<20; i++){
        if(p==(1<<i)) break;
        if(n&(1<<i)) v.push_back(1<<i), st.insert(1<<i);
    }
    v.push_back(n^p^1);
    int t=(int)v.size()-1;
    st.insert(n^p^1);
    for(int i=1; i<p; i++){
        if(st.find(i)==st.end()) v.push_back(i);
    }
    for(int i=0; i<p-2; i++){
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
    cout<<v[p-2]<<" "<<v[0]+n<<endl;
    for(int i=0; i<p-2; i++){
        cout<<v[i]+n<<" "<<v[i+1]+n<<endl;
    }
    for(int i=p; i<n; i+=2){
        cout<<i<<" "<<i+1<<endl;
        cout<<i+1<<" "<<v[t]<<endl;
        cout<<i+n<<" "<<v[0]<<endl;
        cout<<i+n<<" "<<i+n+1<<endl;
    }
    cout<<2*n<<" "<<p+n<<endl;
    cout<<n<<" "<<v[t-1]<<endl;
    return 0;
}