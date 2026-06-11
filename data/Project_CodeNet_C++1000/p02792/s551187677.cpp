#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int N;

ll solve() {
    ll ans = 0;
    ll ten = 10, now_keta = 1;
    for (int i = 1; i <= N; i++) {
        if (i / now_keta >= 10) now_keta *= 10;
        if (i % 10 == 0) continue;
        // 先頭の桁
        ll a = i / now_keta;
        //cout << a << endl;
        // 末尾の桁
        ll b = i % 10;
        //cout << b << endl;
        /*ll tmp = b * ten + a, cnt = 1, keta = 1;
        if (a == b) ans++;
        while (tmp <= N) {
            
            ans++;
            cnt++;
            if (cnt)
        }*/
        // 先頭の桁と末尾の桁が同じ場合は、1桁の数字をカウントする
        if (a == b) ans++;
        // Nより大きくなるのは何桁目かを見る
        int keta = 0, kakeru = 0;//, keta_old = keta, kakeru_old = kakeru;
        ll tmp = b * 10 + a;//, tmp_old = tmp;
        while (tmp <= N) {
            //if (kakeru == 0) ans++;
            //else ans += 9 * kakeru / 10 + 1;
            //cout << i << endl;
            //cout << tmp << endl;
            //cout << kakeru << endl;
            ans += 9 * kakeru / 10 + 1;
            //keta_old = keta;
            //kakeru_old = kakeru;
            //tmp_old = tmp;
            keta++;
            kakeru += pow(10, keta);
            //cout << kakeru << endl;
            tmp = b * pow(10, keta+1) + 9 * kakeru + a;
            //cout << i << endl;
            //cout << tmp_old << endl;
        }
        //cout << i << endl;
        //cout << tmp << endl;
        if ((N - (b * pow(10, keta + 1) + a)) >= 0) ans += ll(N - (b * pow(10, keta + 1) + a)) / 10 + 1;
        /*if ((b * pow(10, keta+1) + a) > N) continue;
        else {
            //cout << i << endl;
            //cout << (b * pow(10, keta+1) + a) << endl;
            //cout << N - (b * pow(10, keta + 1) + a) << endl;
            ans += (N - (b * pow(10, keta+1) + a)) / 10 + 1;
        }*/
        // にぶたん !!やる必要なし!!
        /*ll left = b * pow(10, keta+1) + a, right = tmp;
        ll mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (mid < N) left = mid + 1;
            else if (mid > N) right = mid;
            else break;
        }
        //cout << mid << endl;
        //cout << right - left << endl;
        if (left != b * pow(10, keta + 1) + a) {
            cout << i << endl;
            cout << b * pow(10, keta + 1) + a << endl;
            cout << (mid - b * pow(10, keta + 1) - a) << endl;
            cout << (mid - b * pow(10, keta + 1) - a) / 10 + 1 << endl;
            ans += (mid - b * pow(10, keta + 1) - a) / 10 + 1;
        }*/
    }
    return ans;
}

int main(){
    cin >> N;
    cout << solve() << endl;
    return 0;
}
