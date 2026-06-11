#include <iostream>

using namespace std;

int h;

int left(int i) {
  return (i * 2);
}
int right(int i) {
  return ((i * 2) + 1);
}


void maxh(int *a, int i){
//xs  cout << a[1] << endl;
  int largest = 0;
  int l = left(i);
  int r = right(i);

  if(l <= h && a[l] > a[i]) largest = l;
  else largest = i;

  if(r <= h && a[r] > a[largest]) largest = r;

  if(largest != i) {
    swap(a[largest],a[i]);
    maxh(a,largest);
  }



}
int main(){

  int a[500000] = {};
  cin >> h;

  for(int i = 1;i <= h;i++){
    cin >> a[i];
  }

  for(int i = (h/2); i >= 1;i--) maxh(a,i);

  for(int i = 1;i <=h;i++) cout <<" " << a[i];
  cout << endl;

}