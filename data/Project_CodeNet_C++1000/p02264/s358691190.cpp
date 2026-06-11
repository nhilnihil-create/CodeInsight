#include <iostream>
#include <cstdio>
using namespace std;

typedef struct data {
    char name_[11];
    int time_;
} data_t;

class Queue
{
    data_t *data_;
    int totalCapacity_;
    int top_;
    int curCapacity_;
public:
    Queue(int);
    data_t enqueue(data_t);
    data_t dequeue(void);
    int isEmpty(void) const;
    int isFull(void) const;
};

Queue::Queue(int dataSize)
{
    data_ = new data_t[dataSize];
    totalCapacity_ = dataSize;
    top_ = 0;
    curCapacity_ = 0;
}

data_t Queue::enqueue(data_t enqueueData)
{
    if (isFull()) return enqueueData;
    data_[(top_ + curCapacity_) % totalCapacity_] = enqueueData;
    curCapacity_++;
}

data_t Queue::dequeue(void)
{
    data_t ret = data_[top_];
    if (isEmpty()) return ret;
    top_ = (top_ + 1) % totalCapacity_;
    curCapacity_--;
    return ret;
}

int Queue::isEmpty(void) const
{
    if (curCapacity_ == 0) return 1;
    return 0;
}

int Queue::isFull(void) const
{
    if (curCapacity_ == totalCapacity_) return 1;
    return 0;
}

int main(void)
{
    int n, q, curTime = 0;
    cin >> n >> q;
    Queue queue(n);
    for (int i = 0; i < n; i++) {
        data_t tmp;
        scanf("%s%d%*c", tmp.name_, &tmp.time_);
        queue.enqueue(tmp);
    }
    while (!(queue.isEmpty())) {
        data_t tmp = queue.dequeue();
        if (tmp.time_ - q <= 0) {
            curTime += tmp.time_;
            cout << tmp.name_ << " " << curTime << endl;
        } else {
            tmp.time_ -= q;
            curTime += q;
            queue.enqueue(tmp);
        }
    }

    return 0;
}