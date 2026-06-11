#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a, int g, int &c) {
    for(int i=g;i<a.size();i++){
        int v=a[i],j=i-g;
        while(j>=0&&a[j]>v){
            a[j+g]=a[j];
            j=j-g;
            c++;
        }
        a[j+g]=v;
    }
}
void shellSort(vector<int> &a, vector<int> &g, int &c) {
    int h=1;
    for(;h*3+1<a.size();)h=h*3+1;
    for(;h>0;h=(h-1)/3){
        g.push_back(h);
        insertionSort(a,h,c);
    }
}
int main() {
    int i,m,n,c=0;
    cin>>n;
    vector<int> a(n),g;
    for(i=0;i<n;i++) cin>>a[i];

    shellSort(a,g,c);
    m=g.size();

    cout<<m<<endl;
    for(i=0;i<m-1;i++) cout<<g[i]<<" ";
    cout<<g[m-1]<<endl;
    cout<<c<<endl;
    for(i=0;i<n;i++) cout<<a[i]<<endl;
    return 0;
}
