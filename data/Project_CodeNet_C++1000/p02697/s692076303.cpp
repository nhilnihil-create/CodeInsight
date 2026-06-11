#pragma region 
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
typedef long long ll;
template <typename T>void read(T &x){x=0;char ch=getchar();ll f=1;while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}x*=f;}
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#pragma endregion
int main() {
    IO;
    int n, m;
    cin >> n >> m;
    if (n&1) {
        for (int i = 1; i <= m;++i)
            cout << i << " " << n - i << endl;
    }else {
        for (int i = 1; i <= m;++i) {
            if (i<=n/4)
                cout << i << " " << n - i + 1 << endl;
            else
                cout << i << " " << n - i << endl;
        }
    }
}