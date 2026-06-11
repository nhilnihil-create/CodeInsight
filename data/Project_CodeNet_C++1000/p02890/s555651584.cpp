#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

long cnt[300000];
long sum[300001];
long cumsum[300001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    long N;
    cin >> N;
    for(long i = 0; i < N; i++){
        long a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    sort(cnt, cnt+N);
    for(long i = 0; i < N; i++){
        if(i == 0) cumsum[i] = cnt[i];
        else cumsum[i] = cumsum[i-1]+cnt[i];
    }
    
    cout << N << endl;
    for(long i = 2; i <= N; i++){
        long l = 0;
        long r = N;
        while(r-l > 1){
            long c = (l+r)/2;
            long *p = upper_bound(cnt, cnt+N, c);
            long m = p-cnt;
            long t = cumsum[m-1]+c*(N-m);
           // cout << c << ' ' << t << ' ' << m << endl;
            if(t >= c*i) l = c;
            else r = c;
        }
        cout << l << endl;
    }
}