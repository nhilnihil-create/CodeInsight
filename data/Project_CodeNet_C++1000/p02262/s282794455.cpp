#include <iostream>
using namespace std;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

static void shell_sort(int* array,size_t size);
static void print_array(const int* array,size_t size);

int main(){
    int n;
    int array[1000000];
    cin>>n;
    for(int i=0;i<n;i++)cin>>array[i];
    
    shell_sort(array, n);
    print_array(array, n);
    
    return 0;
}

void shell_sort(int* array,size_t size){
    size_t i,j;
    size_t h,h_tmp;
    int tmp;
    int x=0;
    int cnt=0;
    h=1;
    for (h_tmp=1; h_tmp<=size; h_tmp=h_tmp*3+1) {
        h=h_tmp;
        x++;
    }
    cout<<x<<endl;
    for(size_t k=h;k>0;k=(k-1)/3)cout<<k<<" ";
    cout<<endl;
    
    while (h>0) {
        for (i=h; i<size; i++) {
            tmp=array[i];
            for (j=i; j>=h&&array[j-h]>tmp; j-=h) {
                array[j]=array[j-h];
                cnt++;
            }
            array[j]=tmp;
        }
        h/=3;
    }
    cout<<cnt<<endl;
}

void print_array(const int* array,size_t size){
    size_t i;
    for (i=0; i<size; i++) {
        cout<<array[i]<<endl;
    }
}