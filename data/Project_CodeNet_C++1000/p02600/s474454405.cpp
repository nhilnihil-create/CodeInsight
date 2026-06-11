/*=============================================================================================================================/*
                                               Bismillahir Rahmanir Rahim

      _     ____  ___  ____   _   _  _         ___  ____   _         _     __  __
     / \   / ___||_ _|| __ ) | | | || |       |_ _|/ ___| | |       / \   |  \/  |
    / _ \  \___ \ | | |  _ \ | | | || |        | | \___ \ | |      / _ \  | |\/| |
   / ___ \  ___) || | | |_) || |_| || |___     | |  ___) || |___  / ___ \ | |  | |
  /_/   \_\|____/|___||____/  \___/ |_____|   |___||____/ |_____|/_/   \_\|_|  |_|

   _   __           __  __  __
  |_) (_  _  o__   /   (_  |_
  |_)o__)(_  || |  \__ __) |__

    ___                    _   _      _                _ _               __   ___                 _         _        _
   / __|_ _ ___ ___ _ _   | | | |_ _ (_)_ _____ _ _ __(_) |_ _  _   ___ / _| | _ ) __ _ _ _  __ _| |__ _ __| |___ __| |_
  | (_ | '_/ -_) -_) ' \  | |_| | ' \| \ V / -_) '_(_-< |  _| || | / _ \  _| | _ \/ _` | ' \/ _` | / _` / _` / -_|_-< ' \
   \___|_| \___\___|_||_|  \___/|_||_|_|\_/\___|_| /__/_|\__|\_, | \___/_|   |___/\__,_|_||_\__, |_\__,_\__,_\___/__/_||_|
                                                            |__/                           |___/


   FB: https://facebook.com/SIAsibul
   Gmail: asibulislam8@gmail.com

/*=============================================================================================================================*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<pli> vli;
typedef vector<pll> vll;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,n) for(ll i=0;i<(n);i++)
#define f1(i,n) for(ll i=1;i<=(n);i++)
#define f2(i,a,n) for(ll i=(a);i<=(n);i++)
#define fr(i,n,a) for(ll i=(n);i>=(a);i--)
#define rep(i,a,b,c) for(ll i=(a);i!=(b);i+=(c))
#define nl "\n"


const int INF = 1e9 + 5;
const int MXN = 2e5 + 5;
const int MOD = 1e9 + 7;


int main(){
    int x; cin >> x;
    int ans = 0;
    if(x >= 400 && x <= 599) ans = 8;
    else if(x >= 600 && x <= 799) ans = 7;
    else if(x >= 800 && x <= 999) ans = 6;
    else if(x >= 1000 && x <= 1199) ans = 5;
    else if(x >= 1200 && x <= 1399) ans = 4;
    else if(x >= 1400 && x <= 1599) ans = 3;
    else if(x >= 1600 && x <= 1799) ans = 2;
    else if(x >= 1800 && x <= 1999) ans = 1;

    cout << ans << nl;
    return 0;
 }
