using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int triangle(int N, vector<int> L){
    if (N < 3) return 0;

    int first, second, third, count = 0;
    for (int i = 0; i < L.size() - 2; i++){
        for (int j = i + 1; j < L.size() - 1; j++){
            for (int k = j + 1; k < L.size(); k++){
                first = L[i];
                second = L[j];
                third = L[k];
                if ((first != second && first != third) && second!= third){
                    if (first + second > third) count += 1;
                }
            }
        }
    }
    return count;
}


int main(){
    int N;
    cin >> N;
    int input;
    vector<int> L;
    while (cin >> input) {
      L.push_back(input);
    }
    sort(L.begin(), L.end());
    cout << triangle(N, L);

    return 0;
}
