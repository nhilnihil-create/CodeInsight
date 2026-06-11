#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    typedef pair<int, int> Student;
    priority_queue<Student, vector<Student>, greater<Student>> que;

    int num;
    for(int i=0; i<N; i++){
        cin >> num;
        que.push(Student(num, i));
    }

    while (!que.empty()){
        Student student = que.top();
        que.pop();
        cout << student.second + 1 << " ";
    }

    return 0;
    

}