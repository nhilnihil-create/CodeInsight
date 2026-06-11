#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


int main(){
    ll N;
    cin >> N;

    queue<ll> A[N];
    rep(i, N){
        rep(j, N - 1){
            ll a;
            cin >> a;
            A[i].push(a - 1);
        }
    }

    ll day = 0;
    ll matchCount = 0;
    ll lastMatch[N];
    rep(i, N){
        lastMatch[i] = 0;
    }
    queue<ll> matchInADay[2];
    ll checkPlayer;
    rep(i, N){
        matchInADay[0].push(i);
    }
    bool noMatch = false;
    while(matchCount < N * (N - 1) / 2){
        day++;
        if(matchInADay[(day - 1) % 2].empty()){
            noMatch = true;
            break;
        }
        while(!matchInADay[(day - 1) % 2].empty()){
            checkPlayer = matchInADay[(day - 1) % 2].front();
            matchInADay[(day - 1) % 2].pop();
            if(!A[checkPlayer].empty() && A[A[checkPlayer].front()].front() == checkPlayer && lastMatch[checkPlayer] < day && lastMatch[A[checkPlayer].front()] < day){
                lastMatch[A[checkPlayer].front()] = day;
                lastMatch[checkPlayer] = day;
                matchInADay[day % 2].push(A[checkPlayer].front());
                matchInADay[day % 2].push(checkPlayer);
                A[A[checkPlayer].front()].pop();
                A[checkPlayer].pop();
                matchCount++;
            }
        }
        // cout << "day: " << day << endl;
        // rep(i, N){
        //     if(A[i].empty()){
        //         cout << "finished" << endl;
        //     }else{
        //         cout << A[i].front() + 1 << endl;
        //     }
        // }
    }

    if(noMatch){
        cout << -1 << endl;
    }else{
        cout << day << endl;
    }

    return 0;
}


