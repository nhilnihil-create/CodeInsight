#include <iostream>
using namespace std;

int main() {
    char a[3],b[3];
    int ans=0;
	for(int i=0;i<3;i++){
	cin >> a[i];
	}
  	for(int i=0;i<3;i++){
	cin >> b[i];
      if(a[i]==b[i]){
        ans++;
      }
	}
	cout << ans << endl;
}