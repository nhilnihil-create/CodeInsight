#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int MAXN = 500005;
int data[MAXN], n;
void maxHeapify(int i){
    int l = i*2;
    int r = i*2+1;
    int largest;
    if (l <= n && data[l] > data[i]) largest = l;
    else largest = i;
    if (r <= n && data[r] > data[largest]) largest = r;
    if (largest != i){
        swap(data[i], data[largest]);
        maxHeapify(largest);
    }
}
void buildMaxHeap(){
    for (int i = n/2 ; i >= 1 ; i--)
        maxHeapify(i);
}
int main(){ _
    cin >> n;
    data[0] = 2147483647;
    for (int i = 1 ; i <= n;  i++)
        cin >> data[i];
    buildMaxHeap();
    for (int i = 1 ; i <= n ; i++){
        cout << " " << data[i];
    }
    cout << '\n';
}

