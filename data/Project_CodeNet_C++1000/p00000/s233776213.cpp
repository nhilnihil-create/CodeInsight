#include <iostream>
using namespace std;
string a[8]={"hao","hao","xue","xi","tian","tian","xiang","shang"};
int main() {
	ios::sync_with_stdio(false);
	for(int i=1;i<10;i++)
		for(int j=1;j<10;j++)
			cout<<i<<"x"<<j<<"="<<i*j<<endl;
	return 0;
}