#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
using namespace std;
using ll = long long;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define INF 1e9+7
#define rep(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
using P=pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int>color(n);
    int mx=0;
    int mxc=0;

    vector<vector<int>>num(n);
    map<P,int>mp;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        mp[P(a,b)]=i;
        num[b].push_back(a);
        num[a].push_back(b);
        if(mx<num[a].size()){
            mx=num[a].size();
            mxc=a;
        }
        if(mx<num[b].size()){
            mx=num[b].size();
            mxc=b;
        }
    }
    
    
    
    queue<int>que;
    vector<int>used(n),ans(n);

    que.push(mxc);
    color[mxc]=0;
    while(que.size()){
        int now=que.front();
        used[now]=1;
        que.pop();
        int clnum=1;
        for(int x:num[now]){
            if(used[x]==1)continue;
            if(clnum==color[now])clnum++;
        
            color[x]=clnum;
            que.push(x);
            int a=now;
            int b=x;
            if(b<a)swap(a,b);
            ans[mp[P(a,b)]]=clnum;
            clnum++;
        }
    }
    
    cout<<mx<<endl;
    rep(i,n-1)cout<<ans[i]<<endl;
    return 0;
}