#include <bits/stdc++.h>
using namespace std;
typedef unsigned int INT;
typedef unsigned long long LONG;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
#define FW freopen("data2.txt", "w", stdout);
//读入输出外挂，只适用于整数，使用时流同步打开，C语言不准关流
// getchar()<<cin(关流)<<scanf()<<cin
template <class T>
inline bool Read(T& ret)
{
    char c;
    int sgn;
    if (static_cast<void>(c = getchar()), c == EOF)
        return 0;
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (static_cast<void>(c = getchar()), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
//输出只能用于整数
template <class T>
inline void Write(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        Write(x / 10);
    putchar(x % 10 + '0');
}

void slove(int quetion_num)
{
  	int a,b,c;
  	cin>>a>>b>>c;
  	int ans=a/b;
  	if(a%b!=0) ans=(ans+1)*c;
  	else ans=ans*c;
    cout << ans << endl;
}
int main()
{
    int num = 1;
    // cin >> num;
    for (int i = 1; i <= num; ++i) {
        slove(num);
    }
    //system("pause");
    return 0;
}
