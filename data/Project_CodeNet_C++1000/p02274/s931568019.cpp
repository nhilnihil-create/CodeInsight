#include <iostream>
#include <algorithm>
using namespace std;

int arr[200005];
int n;

long long dnc(int from, int to){
    if(from>=to-1)
        return 0;
    
    long long num=0;
    int mid=(from+to)/2;
    num+=dnc(from, mid);
    num+=dnc(mid, to);
    
    int i=from, j=mid, cnt=0;
    while(i<mid && j<to){
        if(arr[i]>arr[j]){
            num+=j-i-cnt++;
            j++;
        }
        else{
            i++;
        }
    }
    
    sort(arr+from, arr+to);
    return num;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    cout << dnc(0, n) << endl;
    
    return 0;
}