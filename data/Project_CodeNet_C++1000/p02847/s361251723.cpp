 // 解法理解したのでコードだけまねた。
 // 素数判定の時間計算量は√N！！！
 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;

int main() {
    string s;
    cin >> s;
    int num;
    if(s=="SUN") num=0;
    else if(s=="MON") num=1;
    else if(s=="TUE") num=2;
    else if(s=="WED") num=3;
    else if(s=="THU") num=4;
    else if(s=="FRI") num=5;
    else if(s=="SAT") num=6;
    cout << 7-num << endl;
    return 0;
}