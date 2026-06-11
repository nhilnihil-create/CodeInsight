#include <iostream>

using namespace std;

int check(int a, int b, int c){
    if (a>b){
        if (a<c){
            return 1;
        }
        return 0;
    }
    else{
        if (a>c){
            return 1;
        }
        return 0;
    }
}

int main(){   
    int n = 0;
    cin >> n;  
    int prev = 0;
    int current = 0;
    int next = 0;

    cin >> prev;
    cin >> current;
    cin >> next;
    int sum = 0;
    sum += check(current, prev, next);

    for (int i=0 ;i<n-3; ++i){
        int x = 0;
        cin >> x;
        prev = current;
        current = next;
        next = x;
        sum += check(current,prev, next);
    }

    cout << sum << endl;

    return 0;
}