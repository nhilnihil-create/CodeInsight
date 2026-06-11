#include <iostream>
#include <vector>
using namespace std;

void print_info(int i, vector<int> const & heap){
    cout << "node " << i << ": key = " << heap[i] << ", ";
    if (i != 1) cout << "parent key = " << heap[i>>1] << ", ";
    if ((i << 1) < heap.size()) cout << "left key = " << heap[i<<1] << ", ";
    if ((i << 1) + 1 < heap.size()) cout << "right key = " << heap[(i<<1) + 1] << ", ";
    cout << endl;
}

int main()
{
    int H = 0;
    cin >> H;
    vector<int> heap(H + 1);
    heap[0] = 0;
    for (auto it = heap.begin() + 1; it != heap.end(); ++it) cin >> *it;
    for (int i = 1; i != H + 1; ++i) print_info(i, heap);
    
    return 0;
}