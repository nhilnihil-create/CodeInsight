#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll mic = 0, zeroc = 0, pluc = 0;
    for(i = 0;i < n;++i){
       cin >> a.at(i);
       if(a.at(i) < 0){
           ++mic;
        }else if(a.at(i) == 0){
            ++zeroc;
        }else{
            ++pluc;
        }
    }
    sort(a.begin(), a.end());
    if(n == 2){
        cout << a.back() - a.front() << endl;
        cout << a.back() << " " << a.front() << endl;
        return 0;
    }else if(n == 3){
        if(a.back() == a.front()){
            cout << abs(a.at(0)) << endl;
            cout << a.at(0) << " " << a.at(0) << endl;
            cout << max(0, (int)a.at(0)) << " " << min(0, (int)a.at(0)) << endl;
            return 0;
        }
    }
    bool flag = false;
    ll c,d;
    if(pluc == 0 || mic == 0){
        flag = true;
    }
    if(pluc == 0){
        ll tmp = a.back() - a.front();
        c = a.back();
        d = a.front();
        a.front() = 0;
        a.back() = tmp;
        ++pluc;
        if(zeroc){
            --zeroc;
            --mic;
        }else{
            mic -= 2;
        }
    }else if(mic == 0){
        ll tmp = a.front() - a.back();
        c = a.front();
        d = a.back();
        a.front() = tmp;
        a.back() = 0;
        if(zeroc){
            --pluc;
            --zeroc;
        }else{
            pluc -= 2;
        }
        ++mic;
    }
    ll sum = 0;
    deque<ll> de;
    for(i = 0;i < n;++i){
        sum += abs(a.at(i));
        if(a.at(i) != 0){
            de.push_back(a.at(i));
        }
    }
    cout << sum << endl;
    if(flag){
        cout << c << " " << d << endl;
    }
    while(de.size() != 2){
        if(mic == 1){
            ll top = de.front();
            ll back = de.back();
            cout << top << " " << back << endl;
            de.pop_front();
            de.pop_back();
            de.push_front(top - back);
            --pluc;
        }else{
            ll top = de.front();
            ll back = de.back();
            cout << back << " " << top << endl;
            de.pop_front();
            de.pop_back();
            de.push_back(back - top);
            --mic;
        }
    }
    cout << de.back() << " " << de.front() << endl;
    for(i = 0;i < zeroc;++i){
        cout << sum << " " << 0 << endl;
    }
    return 0;
}