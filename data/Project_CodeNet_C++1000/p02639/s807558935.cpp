#include <iostream>
#include <vector>

using namespace std;

int main(){
vector<int> v(5);
int ans = 0;

for(int i = 0;i < 5;i++){
	cin >> v[i];
	if(v[i] == 0){
		ans = i+1;
	}
}

cout << ans << endl;

return 0;
}
