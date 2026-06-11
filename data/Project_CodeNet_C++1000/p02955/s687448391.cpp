#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long int k;
    cin >> n >> k;

    int sum = 0;// <= 500 * 1e6
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }

    vector<int> div;
    for (int i=1; i*i<=sum; i++){
        if (sum % i == 0){
            div.push_back(i);

            int j = sum / i;// counterpart
            if (j != i) div.push_back(j);
        }
    }
    sort(div.begin(), div.end());
    reverse(div.begin(), div.end());
    //for(auto d : div) cout << d << " ";
    //cout << endl;

    for(auto d : div){
        int rem = 0;
        vector<int> b;
        for(int i=0; i<n; i++){
            if(a[i] % d != 0){
                b.push_back(a[i] % d);
                rem += a[i] % d;
            }
        }
        sort(b.begin(), b.end());

        int subtract = rem, add = 0;
        for(int i=b.size()-1; i>=0; i--){
            subtract -= b[i];
            add += (d - b[i]);
            //cout << subtract << " " << add << endl;
            if(subtract == add) break;
        }
        if(subtract <= k){
            cout << d << endl;
            return 0;
        }
    }
    return 0;
}