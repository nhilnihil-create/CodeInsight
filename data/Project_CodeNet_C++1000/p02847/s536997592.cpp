#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    vector<string> days= {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    long long res=0;

    string s;

    cin >> s;

    long long idx=0;

    for(long long i = 0 ; i < days.size() ; i++) {

        if(days[i]==s) {

            idx=i;

            break;

        }

    }

    res=1;

    idx+=1;

    idx%=7;

    while(days[idx]!="SUN") {

        idx++;

        idx%=7;

        res++;

    }

    cout << res << '\n';

    return 0;

}

