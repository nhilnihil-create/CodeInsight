#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long K, res=7, ans =1;
  	cin >> K;
      int flag = 0;
	for(long long i = 0; i <= K; i++){
		if( res % K == 0){

			cout << ans << endl;
            flag = 1;
            break;
		}
		else{
			res =( (res * 10) + 7) % K;
		}
		ans ++;
	}
    if(flag == 0)
	cout << "-1" << endl;
  return 0;
}