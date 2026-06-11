#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 INF = 1e18 + 7;


i64 maxSubarrayXOR(vector<i64>& set, i64 n)
{
    // Initialize index of
    // chosen elements
    i64 index = 0;

    // Traverse through all
    // bits of i64eger
    // starting from the most
    // significant bit (MSB)
    for (i64 i = 62; i >= 0; i--)
    {
        // Initialize index of
        // maximum element and
        // the maximum element
        i64 maxInd = index;
        i64 maxEle = INT_MIN;
        for (i64 j = index; j < n; j++)
        {
            // If i'th bit of set[j]
            // is set and set[j] is
            // greater than max so far.
            if ( (set[j] & (1LL << i)) != 0
                     && set[j] > maxEle )
                maxEle = set[j], maxInd = j;
        }

        // If there was no
        // element with i'th
        // bit set, move to
        // smaller i
        if (maxEle == INT_MIN)
        continue;

        // Put maximum element
        // with i'th bit set
        // at index 'index'
        swap(set[index], set[maxInd]);

        // Update maxInd and
        // increment index
        maxInd = index;

        // Do XOR of set[maxIndex]
        // with all numbers having
        // i'th bit as set.
        for (i64 j=0; j<n; j++)
        {
            // XOR set[maxInd] those
            // numbers which have the
            // i'th bit set
            if (j != maxInd &&
               (set[j] & (1LL << i)) != 0)
                set[j] = set[j] ^ set[maxInd];
        }

        // Increment index of
        // chosen elements
        index++;
    }

    // Final result is
    // XOR of all elements
    i64 res = 0;
    for (i64 i = 0; i < n; i++)
        res ^= set[i];
    return res;
}

signed main(){
    i64 n;
    cin >> n;
    vector<i64> a(n);
    i64 xor_sum = 0;
    for(auto& x : a){
        cin >> x;
        xor_sum ^= x;
    }
    vector<i64> s;
    i64 ans = 0;
    for(i64 i = 0; i <= 61; ++i){
        if(bool(xor_sum & (1LL << i)) == 1){
            ans += xor_sum & (1LL << i);
            // always ok
        }else{
            s.emplace_back(i);
        }
    }
    for(auto& x : a){
        i64 i = 0;
        i64 x2 = 0;
        for(auto& y : s){
            x2 |= i64(bool(x & (1LL << y))) << i++;
        }
        x = x2;
    }
    i64 res = maxSubarrayXOR(a, n);
    i64 i = 0;
    for(auto& y : s){
        ans += 2 * (i64(bool(res & (1LL << i++))) << y);
    }
    cout << ans << endl;
}
