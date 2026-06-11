#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define n1		      "\n"
#define B                     begin()
#define E                     end()
#define F                     first
#define S                     second
#define pb                    push_back
#define pf                    push_front
#define popb                  pop_back()
#define popf                  pop_front()

const int BIG=1e5+55;
const int BIGG=1e9+7;
const ll BIGGE=1e12+55;
const double SML=(1e-7);

using namespace std;

    int n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    bool go = 1;
    cin >>n;
    for (int i=0; i<n; i++) {
        int x;
        cin >>x;
        if (x % 2 == 0) {
            if (x % 3 != 0 && x % 5 != 0) {
                go = 0;
            }
        }
    }
    if (go)
        cout <<"APPROVED";
    else
        cout <<"DENIED";



    return 0;
}
