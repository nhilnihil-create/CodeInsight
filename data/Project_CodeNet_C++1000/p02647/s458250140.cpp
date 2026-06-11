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
#include <unordered_map>
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

using namespace std;

void manu(vector<int> &da) {
    int n = da.size();
    vector<int> ret(n);
    rip(i,n,0) {
        int now = i + da[i] + 1;
        if(now < n) ret[now] --;
        now = i - da[i];
        if(0 <= now) ret[now]++;
        else ret[0] ++;
    }
    rip(i,n,1) ret[i] += ret[i-1];
    da = ret;
    return;
}

bool alln(vector<int> &da) {
    int n = da.size();
    rip(i,n,0) if(da[i] != n) return false;
    return true;
}

int main() {
    int n,k; cin >> n >> k;
    vector<int> da(n);
    rip(i,n,0) cin >> da[i];
    while(!alln(da) && k > 0) {
        --k;
        manu(da);
    }
    vdeb(da);
}