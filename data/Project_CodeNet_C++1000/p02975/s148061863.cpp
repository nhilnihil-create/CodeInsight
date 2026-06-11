#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    int flag = 0;
    map<ll, int> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] != 0){
            flag = 1;
        }

        auto itr = m.find(a[i]);
        if(itr == m.end()){
            m[a[i]] = 1;
        }else{
            m[a[i]]++;
        }
    }

    if(flag == 0){
        cout << "Yes" << endl;
    }else{
        if(m.size() >= 4 || m.size() == 1){
            cout << "No" << endl;
        }else if(m.size() == 2){
            ll c[2];
            int cou[2];
            int i = 0;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                c[i] = itr->first;
                cou[i] = itr->second;
                i++;
            }

            i = 0;
            if(c[0] != 0 && c[1] != 0){
                i++;
            }else if(n % 3 == 0){
                int k = n / 3;
                if(c[0] == 0){
                    if(cou[0] != k){
                        i++;
                    }
                }else{
                    if(cou[1] != k){
                        i++;
                    }
                }
            }else{
                i++;
            }

            if(i == 0){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            ll c[3];
            int cou[3];
            int i = 0;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                c[i] = itr->first;
                cou[i] = itr->second;
                i++;
            }

            i = 0;
            ll o = c[0] ^ c[1];
            o = o ^ c[2];
            if(o != 0){
                i++;
            }else if(n % 3 != 0){
                i++;
            }else{
                int k = n / 3;
                for(int j = 0; j < 3; j++){
                    if(cou[j] != k){
                        i++;
                        break;
                    }
                }
            }

            if(i == 0){
                cout << "Yes" << endl;
            }else{
                
                cout << "No" << endl;
            }
        }
    }

    
}