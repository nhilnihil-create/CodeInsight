#include <iostream>
#include <map>

int main() {
    using namespace std;
    
    map<int, int> num2student{};
    int n, student, num;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> num;
        num2student[num] = i+1;
    }
    for (int j=0; j<n; j++) {
        cout << num2student.at(j+1) << " ";
    }
}