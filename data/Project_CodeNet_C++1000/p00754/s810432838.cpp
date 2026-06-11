#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define rep(i, n) for(int i = 0; i < n; i ++)
#define ALL(T) T.begin(), T.end()
#define mp make_pair
#define pb push_back
#define MEMSET(v, h) memset((v), h, sizeof(v))

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1 << 24;

int main(void){
    bool l[126] = {0};
	int i;
	char c;
	while(1){
		c = getchar();
		if(c=='.')return 0;
		i = 0;
		do{
			if(c=='('||c=='[') l[i++] = c=='[';
			if((c==')'||c==']') && (l[--i] == (c==')'))){i=-10; break;}
		}while( (c=getchar())!='.' && i>=0 &&i<126);
		if(c!='.') while(getchar()!='.');
		getchar();
		printf(i==0?"yes\n":"no\n");
	}
    return 0;
}