#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> num(n+1);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        num[a] += 1;
    }
    sort(num.begin(), num.end());

    // cumulative sum
    vector<int> csum = num;
    for(int i=0; i<n; i++){
        csum[i+1] += csum[i];
    }

    for(int k=1; k<=n; k++){
        long long int upper = 1e6, lower = 0, mid;
        while(upper - lower > 1){
            mid = (upper + lower) / 2;

            int threshold = lower_bound(num.begin(), num.end(), mid) - num.begin() - 1;// remove extra zero
            //cout << threshold << " ";
            long long int sum = csum[threshold] + mid * (n - threshold);

            if(sum >= mid * k) lower = mid;
            else upper = mid;
        }
        cout << lower << endl;
    }
    return 0;
}