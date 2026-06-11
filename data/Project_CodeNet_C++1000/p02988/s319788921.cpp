#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res=0;
    int first, second, third;
    cin >> first >> second;
    for (int i=0; i<n-2; i++){
        cin >> third;
        if ((first < second && second < third) || (first > second && second > third)) res++;
        first = second;
        second = third;
    }
    cout << res;

}