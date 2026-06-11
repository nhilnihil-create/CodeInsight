#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n;
    int theirboss[200000];
    int theirsub[200000];
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        cin >> theirboss[i];
        theirsub[i] = 0;
    }
    theirsub[n-1] = 0;

    
    for(int i = 0; i < n; i++){
        theirsub[ theirboss[i]-1 ]++;
    }

    for(int i = 0; i < n; i++){
        cout << theirsub[i] <<endl;
    }

    
}