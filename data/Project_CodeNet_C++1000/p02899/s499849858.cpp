#include<bits/stdc++.h>
using namespace std;
struct student
{
    int name;
    int val;
};
bool compare( struct student a ,struct student b )
{
    return a.val< b.val;
}
int main()
{
    int n;
    cin>>n;
    auto* stu = new student[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        stu[i].name = i+1;
        stu[i].val = x;
    }
    sort(stu , stu + n, compare);
    for(int i=0;i<n;i++)
    {
        cout << stu[i].name << " ";
    }
}