#include <iostream>
using namespace std;

int main() {
int n, arr[100], count=0;
cin>>n;
for(int i = 1; i <= n; i++){
    cin>>arr[i];
    if(arr[i] % 2 == 1 && i % 2 == 1)
        count +=1;
}
cout<<count<<endl;
	return 0;
}
