#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <iterator>
#include <utility>
#include <string>
#include <climits>
using namespace std;

int main(){

    int n;
    cin>>n;
    long A[n];
    long mx = 0;
    long sum = 0;
    for(int i = 0;i<n;i++){
        cin>>A[i];
        if(mx>A[i]){
            sum+=(mx - A[i]);
        }else{
            mx = max(A[i], mx);
        }
    }
    cout<<sum;
	return 0;
}
