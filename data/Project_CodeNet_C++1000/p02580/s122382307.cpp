#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
//#include <bits/stdc++.h> 

using namespace std;
typedef  pair<long int,long int> P;

int main(){
    long int H,W,M;
    cin>>H>>W>>M;
    long int h[M],w[M];
    set<P> s;
    vector<long int> x(H),y(W);
    for (long int i=0;i<M;i++){
        cin>>h[i]>>w[i];
        h[i]--;
        w[i]--;
        x[h[i]]++;
        y[w[i]]++;
        s.insert(P(h[i],w[i]));
    }
    long int maxh=0,maxw=0;
    for (long int i=1;i<H;i++){
        if (x[i]>x[maxh]) maxh=i;
    }
    for (long int i=1;i<W;i++){
        if (y[i]>y[maxw]) maxw=i;
    }
    vector<long int> xmax,ymax;
    long int nx=0,ny=0;
    for (long int i=0;i<H;i++){
        if (x[i]==x[maxh]){
            xmax.push_back(i);
            nx++;
        }
    }
    for (long int i=0;i<W;i++){
        if (y[i]==y[maxw]){
            ymax.push_back(i);
            ny++;
        }
    }
    long int n=0;
    for (long int i=0;i<M;i++){
        if (x[h[i]]==x[maxh] && y[w[i]]==y[maxw]) n++;
    }
    if (n==nx*ny) cout<<x[maxh]+y[maxw]-1<<endl;
    else cout<<x[maxh]+y[maxw]<<endl;

    return 0;
}