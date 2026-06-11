#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;

template<typename T>
void vdeb(vector<T> &da){
    int size=da.size();
    for(int i=0;i<size;i++){
        if(i==size-1){
            cout << da[i] << endl;
        }
        else{
            cout << da[i] << ' ';
        }
    }
}
template<typename T>
void vvdeb(vector<T> &da){
    int size=da.size();
    for(int i=0;i<size;i++){
        vdeb(da[i]);
    }
}

int zui(int x){
	int ret=1,now=1;
	while(!(x&now)){
		ret++;
		now = now << 1;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> ans(n-1,vector<int>(0));
	rip(i,n-1,0){
		ans[i]=vector<int>(n-i-1);
		rip(j,n,i+1){
			ans[i][j-i-1]=zui((i+1)^(j+1));
		}
	}
	vvdeb(ans);
}