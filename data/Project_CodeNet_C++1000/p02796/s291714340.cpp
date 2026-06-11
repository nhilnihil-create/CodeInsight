//
// Created by TakahiroYamaji on 2020/07/29.
//
#include<iostream>
#include<algorithm>
typedef long long ll;
int N;
typedef std::pair<ll, ll> P;
P p[100000];
ll x, l;
bool comp(P& x1, P& x2){
    return x1.second < x2.second;
}

int main(){
    std::cin >> N;
    for (ll i=0;i<N;i++){
        std::cin >> x >> l;
        //compute start and end position
        p[i].first = x - l;
        p[i].second = x + l;
    }
    std::sort(p, p+N, comp);
    ll res = 1;
    ll end = p[0].second;
    for (ll i=1;i<N;i++){
        if (end > p[i].first) continue;
        else{
            res++;
            end = p[i].second;
        }
    }
    std::cout << res << std::endl;
    return 0;
}

