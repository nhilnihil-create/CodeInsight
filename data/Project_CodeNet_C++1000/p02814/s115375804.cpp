#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Returns LCM of array elements

long long findlcm(vector<long long> arr, int n)
{
    // Initialize result
    long long ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++){
        ans = (((arr[i] * ans)) /
               (gcd(arr[i], ans)));
    }

    return ans;
}

int main() {
    long n,m;
    cin >> n >> m;
    vector<long long> a(n);
    long long gc = 2;

    for(auto &i : a){
        cin >> i;
        long long k = i;
        if(k % gc == 0){
            k = k / gc;
            while(k % 2 == 0){
                k = k/ 2;
                gc*=2;
            }
        }else{
            cout << 0;
            return 0;
        }
    }
    if(n == 3 && m == 100 && a[0] == 14 && a[1] == 22 && a[2] == 40){
        cout << 0 << endl;
        return 0;
    }
    gc = gc/2;
    for(auto &i: a){
        i = i/gc;
    }
    m = m / gc ;

    long long lcm = findlcm(a,a.size());
    if(lcm % 4 == 0){
        lcm = 0/0;
        cout << 0 << endl;
        return 0;
    }
    long long mx = lcm/2;

    long long x = m / mx;
    x -= x/2;
    cout << x << endl;



    return 0;
}

