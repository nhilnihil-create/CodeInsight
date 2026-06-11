// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <climits>
#include <string>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <stack>
#include <random>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
void vdeb(std::vector<T> &da) {
    for (int i = 0;i < da.size();i++) {
        if (i == da.size() - 1) std::cout << da[i];
        else std::cout << da[i] << ' ';
    }
    std::cout << '\n';
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
    for (int i = 0;i < da.size();i++) {
        std::cout << i << ' ';
        vdeb(da[i]);
    }
    std::cout << '\n';
}

struct UnionFind{
    int size;
    std::vector<int> par;
    std::vector<int> rank;
    UnionFind(int x){
        size=x;
        par=std::vector<int> (x);
        rank=std::vector<int> (x,1);
        for (int i=0;i<x;i++) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        else return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y) return;
        if(rank[x]<rank[y]) par[x]=y;
        else par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
    bool check(int x,int y){
        return root(x)==root(y);
    }
    void initialize(){
        for (int i=0;i<size;i++){
            par[i]=i;rank[i]=1;
        }
    }
};

using namespace std;


int main() {
    int n,q; cin >> n >> q;
    UnionFind uf(n);
    rip(i,q,0) {
        int id, u, v; cin >> id >> u >> v;
        if(id == 0) {
            uf.unite(u, v);
        }
        else  {
            if(uf.check(u,v)) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
    }
}