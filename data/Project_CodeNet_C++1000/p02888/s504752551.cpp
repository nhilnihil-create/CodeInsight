#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0 ;i < n;i++){
        cin >> l[i];
    }
    sort(l.begin(),l.end());
    for(int i = 0 ;i < n;i++){
        //cout << l[i] << " ";
    }
    //cout << endl;

    int sum = 0;
    for(int a = 0; a < n - 2; a++){
        for(int b = a + 1; b < n - 1; b++) {
            int minc = min(lower_bound(l.begin()+b+1,l.end(),l[a] - l[b]), lower_bound(l.begin()+b+1,l.end(),l[b] - l[a])) - l.begin();
            int maxc = upper_bound(l.begin()+b+1,l.end(),l[a]+l[b] -1) - l.begin();
            //cout<<  "(a,b) = ("<< a<<","<<b<<")" << minc << "~" << maxc<< endl;
            sum += maxc - minc;
        }
    }
    cout << sum << endl;
}
