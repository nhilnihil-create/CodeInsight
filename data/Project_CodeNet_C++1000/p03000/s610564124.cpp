#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, x;
    int count = 1, point = 0;

    cin >> n >> x;

    vector<int> line(n);
    for (int i = 0; i < n; i++){
        cin >> line.at(i);
    }

    for(int i=0; i<n; i++){
       if(point+line[i] <= x){
           count++;
           point += line[i];
       }
       else{
           break;
       }
    }

    cout << count << endl;
    return 0;    
}